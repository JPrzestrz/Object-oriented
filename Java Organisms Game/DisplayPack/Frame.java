package DisplayPack;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import ProjectWorld.WorldManager;
import ProjectWorld.Human;
import javax.swing.JLabel;
/**
 *
 * @author kprze
 */
public class Frame extends JFrame{
    
    private WorldManager worldManager;
    public WorldManager getWorldManager()
    {
        return worldManager;
    }
    
    private Human human;
    public Human getHuman()
    {
        return human;
    }
    
    private final SimulatorArea poleGry; 
    
    public Frame(int x, int y, WorldManager worldManager)
    {
        super("Jakub Przestrzelski s184850");
        JLabel author;
        author = new JLabel("Jakub Przestrzelski 184850");
        add(author);
        this.worldManager=worldManager;
	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(true);
        setSize(55*(x+1), 55*(y+1));
        setLayout(new FlowLayout());
        KeyListenerFrame escExit = new KeyListenerFrame();
        addKeyListener(escExit);
        poleGry = new SimulatorArea(x, y, worldManager);
        add(poleGry);
        poleGry.setBackground(new Color(0, 0, 0));
        poleGry.setLocation(0,0);
        poleGry.setPreferredSize(new Dimension(45*x,45*y));
	setVisible(true);
        JLabel help;
        help = new JLabel("s - save, l - load, arrows - move, right-click - add organism, esc - exit");
        //help.setBounds(0,0,100,20);
        add(help);
    }
    
    public void setFieldText(String text, int x, int y)
    {
        poleGry.setFieldText(text, x, y);
    }
    public void clearSimArea()
    {
        poleGry.clearArea();
    }
}
