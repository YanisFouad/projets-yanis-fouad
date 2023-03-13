import java.awt.*;

@SuppressWarnings("serial")
public class Score extends Rectangle{
	
	// Les dimensions du jeu
	static int GAME_WIDTH;
	static int GAME_HEIGHT;
	
	// Le score des deux joueurs
	int player1;
	int player2;
	
	public Score(int GAME_WIDTH, int GAME_HEIGHT) {
		Score.GAME_WIDTH = GAME_WIDTH;
		Score.GAME_HEIGHT = GAME_HEIGHT;
	}
	
	// Affiche le score des deux joueurs sur l'écran.
	public void draw(Graphics g) {
		g.setColor(Color.white);
		g.setFont(new Font("Consolas", Font.PLAIN, 60));
		
		// Dessine une ligne verticale au milieu de l'écran
		g.drawLine(GAME_WIDTH/2, y, GAME_WIDTH/2, GAME_HEIGHT);
		
		// Affiche le score du joueur 1
		g.drawString(String.valueOf(player1/10)+String.valueOf(player1%10), (GAME_WIDTH/2)-85, 50);
		// Affiche le score du joueur 2
		g.drawString(String.valueOf(player2/10)+String.valueOf(player2%10), (GAME_WIDTH/2)+20, 50);
	}
}
