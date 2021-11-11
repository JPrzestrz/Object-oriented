package DisplayPack;
import ProjectWorld.Coords;
import ProjectWorld.WorldManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
/**
 *
 * @author kprze
 */
public class NewOrganismActionListener implements ActionListener{
    private String name;
    private int x;
    private int y;
    WorldManager worldManager;
    
    public NewOrganismActionListener(int x, int y, WorldManager worldManager, String name)
    {
        this.name=name;
        this.x=x;
        this.y=y;
        this.worldManager=worldManager;
    }
    @Override
    public void actionPerformed(ActionEvent event)
    {
        worldManager.addOrganism(new Coords(x,y),name);
        worldManager.drawWorld();
    }
}
