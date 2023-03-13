import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class Paddle extends Rectangle{
	
	// Identifiant du joueur
	int playerId;
	
	// Vitesse de déplacement de la raquette
	int yVelocity;
	int speed = 10;
	
	public Paddle(int x, int y, int PADDLE_WIDTH, int PADDLE_HEIGHT, int id) {
		super(x,y,PADDLE_WIDTH,PADDLE_HEIGHT);
		this.playerId = id;
		
	}
	// Méthode appelée lorsqu'une touche est enfoncée.
	// La raquette du joueur concerné est déplacée en fonction de la touche enfoncée.
	public void keyPressed(KeyEvent e) {
		switch(playerId) {
		case 1:
			if(e.getKeyCode()==KeyEvent.VK_Z) {
				// Déplacement de la raquette du joueur 1 vers le haut
				setYDirection(-speed);
				move();
			}
			if(e.getKeyCode()==KeyEvent.VK_S) {
				// Déplacement de la raquette du joueur 1 vers le bas
				setYDirection(speed);
				move();
			}
			break;
		case 2:
			if(e.getKeyCode()==KeyEvent.VK_UP) {
				// Déplacement de la raquette du joueur 2 vers le haut
				setYDirection(-speed);
				move();
			}
			if(e.getKeyCode()==KeyEvent.VK_DOWN) {
				// Déplacement de la raquette du joueur 2 vers le bas
				setYDirection(speed);
				move();
			}
			break;
		}
	}
	
	// Méthode appelée lorsqu'une touche est relâchée.
	// La raquette du joueur concerné est arrêtée en fonction de la touche relâchée.
	public void keyReleased(KeyEvent e) {
		switch(playerId) {
		case 1:
			if(e.getKeyCode()==KeyEvent.VK_Z) {
				// Arrêt du déplacement vers le haut de la raquette du joueur 1
				setYDirection(0);
				move();
			}
			if(e.getKeyCode()==KeyEvent.VK_S) {
				// Arrêt du déplacement vers le bas de la raquette du joueur 1
				setYDirection(0);
				move();
			}
			break;
		case 2:
			if(e.getKeyCode()==KeyEvent.VK_UP) {
				// Arrêt du déplacement vers le haut de la raquette du joueur 2
				setYDirection(0);
				move();
			}
			if(e.getKeyCode()==KeyEvent.VK_DOWN) {
				// Arrêt du déplacement vers le bas de la raquette du joueur 2
				setYDirection(0);
				move();
			}
			break;
		}
	}
	
	// Méthode permettant de définir la direction verticale de la raquette 
	// en fonction de la touche pressée par le joueur
	public void setYDirection(int yDirection) {
		yVelocity = yDirection;
	}
	
	// Méthode permettant de déplacer la raquette en fonction de sa direction
	public void move() {
		y = y + yVelocity;
	}
	
	// Méthode permettant de dessiner la raquette avec sa couleur correspondant à son joueur
	public void draw(Graphics g) {
		if(playerId == 1) {
			g.setColor(Color.blue);
		}else {
			g.setColor(Color.red);
		}
		g.fillRect(x, y, width, height);
	}
}
