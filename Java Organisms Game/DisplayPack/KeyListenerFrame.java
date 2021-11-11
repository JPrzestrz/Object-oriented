package DisplayPack;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import ProjectWorld.Coords;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import ProjectWorld.WrongWorldSizeException;
/**
 *
 * @author kprze
 */
public class KeyListenerFrame implements KeyListener{
    @Override
    public void keyPressed(KeyEvent event)
    {
        Frame father=(Frame)event.getSource();
        switch (event.getKeyCode())
        {
            case KeyEvent.VK_ESCAPE:
                father.dispose();
                return;
                
            case KeyEvent.VK_UP:
                father.getWorldManager().executeTurn(new Coords(0,-1));
                break;
                
            case KeyEvent.VK_DOWN:
                father.getWorldManager().executeTurn(new Coords(0,1));
                break;
                
            case KeyEvent.VK_LEFT:
                father.getWorldManager().executeTurn(new Coords(-1,0));
                break;
                
            case KeyEvent.VK_RIGHT:
                father.getWorldManager().executeTurn(new Coords(1,0));
                break;
                
            case KeyEvent.VK_SPACE:
                father.getWorldManager().executeTurn(new Coords(0,0));//special ability
                break;
                
            case KeyEvent.VK_S:
        {
            try {
                father.getWorldManager().save();
            } catch (FileNotFoundException ex) {
                Logger.getLogger(KeyListenerFrame.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
                break;
                
            case KeyEvent.VK_L:
        {
            try {
                father.getWorldManager().load();
            } catch (WrongWorldSizeException ex) {
                Logger.getLogger(KeyListenerFrame.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
                break;
        }
    }
    @Override
    public void keyReleased(KeyEvent event)
    {
        
    }
    
    @Override
    public void keyTyped(KeyEvent event)
    {
        
    }
}
