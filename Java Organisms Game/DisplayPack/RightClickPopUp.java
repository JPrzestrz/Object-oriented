package DisplayPack;
import ProjectWorld.WorldManager;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
/**
 *
 * @author kprze
 */
public class RightClickPopUp extends JPopupMenu{
    public int menuLength;
    JMenuItem[] menuItems;
    public RightClickPopUp(int x, int y, WorldManager worldManager)
    {
        this.menuLength = 10;
        
        menuItems = new JMenuItem[menuLength];
        menuItems[0] = new JMenuItem("Antelope");
        menuItems[1] = new JMenuItem("Fox");
        menuItems[2] = new JMenuItem("Sheep");
        menuItems[3] = new JMenuItem("Turtle");
        menuItems[4] = new JMenuItem("Wolf");
        menuItems[5] = new JMenuItem("Grass");
        menuItems[6] = new JMenuItem("Sow Thistle");
        menuItems[7] = new JMenuItem("Belladonna");
        menuItems[8] = new JMenuItem("Guarana");
        menuItems[9] = new JMenuItem("Sosnowsky's Hogweed");
        for(int i=0;i<menuLength;i++)
        {
            add(menuItems[i]);
            menuItems[i].addActionListener(new NewOrganismActionListener(x,y,worldManager,menuItems[i].getText()));
        }
    }
}
