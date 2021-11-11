package DisplayPack;
import ProjectWorld.WorldManager;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.GridLayout;
/**
 *
 * @author kprze
 */
public class SimulatorArea extends JPanel{
    private WorldFieldJPanel[][] animalMatrix;
    private final int sizeX;
    private final int sizeY;
    
    public SimulatorArea(int x_a, int y_a, WorldManager worldManager)
    {
        sizeX=x_a;
        sizeY=y_a;
        
        setLayout(new GridLayout(x_a,y_a,3,3));
        this.animalMatrix= new WorldFieldJPanel[x_a][y_a];
        for(int y=0;y<sizeY;y++)
        {
            for(int x=0;x<sizeX;x++)
            {
                animalMatrix[x][y]=new WorldFieldJPanel(x,y,worldManager);
                add(animalMatrix[x][y]);
            }
        }
    }
    public void setFieldText(String text, int x, int y)
    {
        animalMatrix[x][y].setText(text);
    }
    public void clearArea()
    {
        for(int i=0;i<sizeY;i++)
        {
            for(int j=0;j<sizeX;j++)
            {
                animalMatrix[j][i].clearField();
            }
        }
    }
}
