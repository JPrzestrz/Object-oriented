package DisplayPack;
import ProjectWorld.WorldManager;
import java.awt.Color;
import javax.swing.JPanel;
import javax.swing.JLabel;

/**
 *
 * @author kprze
 */
public class WorldFieldJPanel extends JPanel{
    private JLabel text;
    
    public WorldFieldJPanel(int x, int y, WorldManager worldManager)
    {
        RightMouseMenu rigtMouseMenu = new RightMouseMenu(x,y,worldManager);
        addMouseListener(rigtMouseMenu);
        setBackground(Color.gray);
        text=new JLabel();
        add(text);
    }
    public void clearField()
    {
        text.setText("");
        setBackground(Color.gray);
    }
    public void setText(String newText)
    {
        text.setText(newText);
        if(newText=="Human")setBackground(Color.yellow);
        else if(newText=="Grass" || newText=="Hogweed" || newText=="Sow Thistle" || newText=="Belladonna" || newText=="Guarana")setBackground(Color.green);
        else setBackground(Color.red);
    }
}
