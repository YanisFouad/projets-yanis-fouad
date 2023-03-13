import java.awt.*;
import java.util.*;

@SuppressWarnings("serial")
public class Ball extends Rectangle{
	
	Random random; // objet Random utilisé pour générer des directions aléatoires
	int xVelocity; // direction horizontale de la balle
	int yVelocity; // direction verticale de la balle
	int randomXDirection; // valeur aléatoire utilisée pour déterminer la direction horizontale initiale de la balle
	int randomYDirection; // valeur aléatoire utilisée pour déterminer la direction verticale initiale de la balle
	int initialSpeed = 2; // vitesse initiale de la balle
	
	public Ball(int x, int y, int width, int height) {
		super(x,y,width,height);
		random = new Random();
				
		randomXDirection = random.nextInt(2); // génère une valeur aléatoire de 0 ou 1
		if(randomXDirection == 0) { // si la valeur est 0
			randomXDirection--; // la direction horizontale sera -1 (vers la gauche)
		}
		setXDirection(randomXDirection*initialSpeed); // définit la direction horizontale initiale de la balle
		
		randomYDirection = random.nextInt(2); // génère une valeur aléatoire de 0 ou 1
		if(randomYDirection == 0) { // si la valeur est 0
			randomYDirection--; // la direction verticale sera -1 (vers le haut)
		}
		setYDirection(randomYDirection*initialSpeed); // définit la direction verticale initiale de la balle
	}
	
	public void setXDirection(int randomXDirection) {
		xVelocity = randomXDirection;
	}
	public void setYDirection(int randomYDirection) {
		yVelocity = randomYDirection;
	}
	public void move() {
		x += xVelocity; // déplace la balle horizontalement selon sa direction
		y += yVelocity; // déplace la balle verticalement selon sa direction
	}
	public void draw(Graphics g) {
		g.setColor(Color.white);
		g.fillOval(x, y, height, width); // dessine la balle sous forme d'un cercle blanc
	}
	
}
