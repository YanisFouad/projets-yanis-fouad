import java.awt.Color;
import java.awt.Desktop;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URI;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

@SuppressWarnings("serial")
public class GameFrame extends JFrame implements ActionListener{
	// Déclaration des variables
	GamePanel panel; // Le panneau de jeu
	int menuHeight; // La hauteur du menu
	JMenuBar menuBar; // La barre de menu
	JMenu optionMenu; // Le menu des options
	JMenuItem newGameItem; // L'élément de menu pour commencer une nouvelle partie
	JMenuItem helpItem; // L'élément de menu pour obtenir de l'aide
	JMenuItem leaveItem; // L'élément de menu pour quitter
	
	// Constructeur de la classe GameFrame
	public GameFrame() {
		// Initialisation des éléments de la barre de menu
		menuBar = new JMenuBar();
		optionMenu = new JMenu("Options");
		newGameItem = new JMenuItem("Nouvelle Partie");
		helpItem = new JMenuItem("Aide");
		leaveItem = new JMenuItem("Quitter");
		
		// Ajout d'un écouteur d'événements pour chaque élément de menu
		newGameItem.addActionListener(this);
		helpItem.addActionListener(this);
		leaveItem.addActionListener(this);
		
		// Ajout des éléments de menu au menu et du menu à la barre de menu
		menuBar.add(optionMenu);
		optionMenu.add(newGameItem);
		optionMenu.add(helpItem);
		optionMenu.add(leaveItem);
		
		// Ajout de la barre de menu à la fenêtre de jeu
		this.setJMenuBar(menuBar);
		
		// Calcul de la hauteur de la barre de menu
		menuHeight = menuBar.getHeight();
		
		// Initialisation du panneau de jeu avec la hauteur du menu
		panel = new GamePanel(menuHeight);
		
		// Configuration de la fenêtre de jeu
		this.add(panel);
		this.setTitle("Pong");
		this.setResizable(false);
		this.setBackground(Color.black);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
	
	// Méthode qui est appelée lorsque l'utilisateur clique sur un élément de menu
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == newGameItem) { // Si l'utilisateur a cliqué sur "Nouvelle Partie"
			dispose(); // Ferme la fenêtre actuelle
	        String[] args = {}; // Initialise les arguments de la nouvelle partie à vides
	        PongGame.main(args); // Démarre une nouvelle partie
		}
		if(e.getSource() == helpItem) { // Si l'utilisateur a cliqué sur "Aide"
			try {
                Desktop.getDesktop().browse(new URI("https://github.com/YanisFouad/projets-yanis-fouad/blob/pong/README.md")); // Ouvre le lien vers le fichier README.md sur GitHub
            } catch (Exception ex) {
                ex.printStackTrace(); // Si une erreur survient, affiche la pile d'erreurs
            }
		}
		if(e.getSource() == leaveItem) { // Si l'utilisateur a cliqué sur "Quitter"
			System.exit(0); // Ferme le programme
		}
	}
}
