package DisplayPack;
import ProjectWorld.WorldManager;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
/**
 *
 * @author kprze
 */
public class RightMouseMenu extends MouseAdapter{
    private int x;
    private int y;
    private WorldManager worldManager;
    
    public RightMouseMenu(int x, int y, WorldManager worldManager)
    {
        this.worldManager=worldManager;
        this.x=x;
        this.y=y;
    }
    @Override
    public void mouseClicked(MouseEvent event)
    {
        if(MouseEvent.BUTTON3==event.getButton())
        {
            RightClickPopUp menu=new RightClickPopUp(x,y,worldManager);
            menu.show(event.getComponent(),event.getX(),event.getY());
        }
    }
}
