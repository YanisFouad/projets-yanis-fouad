import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class GamePanel extends JPanel implements Runnable{

	// Définition des constantes de la taille de l'écran de jeu, de la taille de la balle, de la raquette, ainsi que la taille de l'écran
	static final int GAME_WIDTH = 1000;
	static int GAME_HEIGHT = (int)(GAME_WIDTH * (0.5555)); // Respect des mesures d'une table de Ping Pong
	static final Dimension SCREEN_SIZE = new Dimension(GAME_WIDTH,GAME_HEIGHT);
	static final int BALL_DIAMETER = 20;
	static final int PADDLE_WIDTH = 25;
	static final int PADDLE_HEIGHT = 100;

	// Déclaration des variables
	Thread gameThread;
	Image image;
	Graphics graphics;
	Random random;
	Paddle paddlePlayer1;
	Paddle paddlePlayer2;
	Ball ball;
	Score score;

	// Constructeur de la classe GamePanel prenant en paramètre la hauteur du menu
	public GamePanel(int menuHeight) {
		
		// Calcul de la hauteur de l'écran de jeu
		GamePanel.GAME_HEIGHT = (int)(GAME_WIDTH * (0.5555)) + menuHeight;
		
		// Création des raquettes, de la balle et du score
		newPaddles();
		newBall();
		score = new Score(GAME_WIDTH,GAME_HEIGHT);
		
		// Activation de la gestion des touches
		this.setFocusable(true);
		this.addKeyListener(new ActionListener());
		
		// Définition de la taille de l'écran
		this.setPreferredSize(SCREEN_SIZE);
		
		// Lancement du thread de jeu
		gameThread = new Thread(this);
		gameThread.start();
	}

	// Méthode pour créer une nouvelle balle
	public void newBall() {
		ball = new Ball((GAME_WIDTH/2)-(BALL_DIAMETER/2),(GAME_HEIGHT/2)-(BALL_DIAMETER/2),BALL_DIAMETER,BALL_DIAMETER);
	}

	// Méthode pour créer de nouvelles raquettes
	public void newPaddles() {
		paddlePlayer1 = new Paddle(0,(GAME_HEIGHT/2)-(PADDLE_HEIGHT/2), PADDLE_WIDTH, PADDLE_HEIGHT, 1);
		paddlePlayer2 = new Paddle(GAME_WIDTH-PADDLE_WIDTH,(GAME_HEIGHT/2)-(PADDLE_HEIGHT/2), PADDLE_WIDTH, PADDLE_HEIGHT, 2);
	}

	// Méthode pour dessiner le jeu
	public void paint(Graphics g) {
		// Création d'une image avec les dimensions de l'écran de jeu
		image = createImage(getWidth(),getHeight());
		graphics = image.getGraphics();
		draw(graphics);
		// Affichage de l'image créée sur le JPanel
		g.drawImage(image,0,0,this);
	}

	// Méthode pour dessiner les éléments du jeu
	public void draw(Graphics g) {
		paddlePlayer1.draw(g);
		paddlePlayer2.draw(g);
		ball.draw(g);
		score.draw(g);
	}

	// Méthode pour déplacer les éléments du jeu
	public void move() {
		paddlePlayer1.move();
		paddlePlayer2.move();
		ball.move();
	}
	
	//
	public void checkCollision() {
		// Vérifie si la balle atteint le bord supérieur ou inférieur
		if(ball.y <= 0) {
			ball.setYDirection(-ball.yVelocity);
		}
		if(ball.y >= GAME_HEIGHT-BALL_DIAMETER) {
			ball.setYDirection(-ball.yVelocity);
		}
		
		// Vérifie si la balle entre en collision avec la raquette du joueur 1 ou du joueur 2
		// et augmente sa vitesse
		if(ball.intersects(paddlePlayer1)) {
			ball.xVelocity = Math.abs(ball.xVelocity);
			ball.xVelocity++;
			if(ball.yVelocity > 0) {
				ball.yVelocity++;
			}
			else
				ball.yVelocity--;
			ball.setXDirection(ball.xVelocity);
			ball.setYDirection(ball.yVelocity);
			
		}
		if(ball.intersects(paddlePlayer2)) {
			ball.xVelocity = Math.abs(ball.xVelocity);
			ball.xVelocity++;
			if(ball.yVelocity > 0) {
				ball.yVelocity++;
			}
			else
				ball.yVelocity--;
			ball.setXDirection(-ball.xVelocity);
			ball.setYDirection(ball.yVelocity);
			
		}
		
		// Vérifie si la raquette du joueur 1 ou du joueur 2 sort de l'écran
		if(paddlePlayer1.y <= 0) {
			paddlePlayer1.y = 0;
		}
		if(paddlePlayer1.y >= GAME_HEIGHT-PADDLE_HEIGHT) {
			paddlePlayer1.y = GAME_HEIGHT-PADDLE_HEIGHT;
		}
		if(paddlePlayer2.y <= 0) {
			paddlePlayer2.y = 0;
		}
		if(paddlePlayer2.y >= GAME_HEIGHT-PADDLE_HEIGHT) {
			paddlePlayer2.y = GAME_HEIGHT-PADDLE_HEIGHT;
		}
		
		// Ajoute 1 point au joueur correspondant
		if(ball.x <=0) {
			// Ajout d'un point pour le joueur 2
			score.player2++;
			newPaddles();
			newBall();
		}
		if(ball.x >=GAME_WIDTH-BALL_DIAMETER) {
			// Ajout d'un point pour le joueur 1
			score.player1++;
			newPaddles();
			newBall();			
		}
	}
	
	// Gère la boucle du jeu, elle maintient un taux de rafraichissement de 60 images/s
	public void run() {
		// Temps de dernière mise à jour
		long lastTime = System.nanoTime();
		// Nombre de ticks par seconde
		double amoutOfTicks = 60.0;
		// Durée d'un tick en nanosecondes
		double ns = 1000000000 / amoutOfTicks;
		// Écart entre deux mises à jour
		double delta = 0;
		while(true) {
			// Temps actuel
			long now = System.nanoTime();
			// Calcule le temps écoulé depuis la dernière mise à jour
			delta += (now - lastTime)/ns;
			// Met à jour le temps de la dernière mise à jour
			lastTime = now;
			// Si le temps écoulé est suffisant pour faire un tick, on met à jour le jeu
			if(delta >= 1) {
				move();
				checkCollision();
				repaint();
				delta--;
			}
		}
	}
	
	// Gère les entrées de l'utilisateur
	public class ActionListener extends KeyAdapter{
		// Lorsque l'utilisateur appuie sur une touche du clavier.
		public void keyPressed(KeyEvent e) {
			paddlePlayer1.keyPressed(e);
			paddlePlayer2.keyPressed(e);
		}
		// Lorsque l'utilisateur relâche une touche du clavier.
		public void keyReleased(KeyEvent e) {
			paddlePlayer1.keyReleased(e);
			paddlePlayer2.keyReleased(e);
		}
	}
}
