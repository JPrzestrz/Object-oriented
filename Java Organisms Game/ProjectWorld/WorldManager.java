package ProjectWorld;
import DisplayPack.Frame;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author kprze
 */
public class WorldManager extends World{
    private void generateWorld()
    {
        human=(Human)this.addOrganism(new Coords(0,0), "Human");
    }

    public void save() throws FileNotFoundException
    {
        PrintWriter save_a = new PrintWriter("save.txt");
        for(ArrayList <Organism> initiative : organisms)
        {
            save_a.print(initiative.size()+String.format("%n"));
            for(Organism actual : initiative)
            {
                save_a.print(actual.getName()+" "+actual.getLocation().x+" "+actual.getLocation().y+" "+actual.getAge()+" "+actual.getStrength()+String.format("%n"));
            }
        }
        save_a.close();
    }
    
    public void load() throws WrongWorldSizeException
    {
        for(ArrayList list : organisms)
        {
            list.clear();
        }
        File file = new File("save.txt");
        Scanner scanner;
        try
        {
            scanner = new Scanner(file);
        }
        catch(FileNotFoundException ex)
        {
            return;
        }
        for(int i=0;i<10;i++)
        {
            
            int count = scanner.nextInt();
            for(int j=0;j<count;j++)
            {
                String name=scanner.next();
                Coords coords = new Coords(scanner.nextInt(),scanner.nextInt());
                Organism newOrg = this.addOrganism(coords, name);
                newOrg.setAge(scanner.nextInt());
                if(newOrg.getName()!="Human") {
                } else {
                    this.human=(Human) newOrg;
                }
                newOrg.setStrength(scanner.nextInt());
                if(coords.x>=size.x || coords.y>=size.y)
                {
                    throw new WrongWorldSizeException();
                }
            }
        }
        this.drawWorld();
    }
    
    private Human human;
    /**
     *
     * @param humanMove
     */
    public void executeTurn(Coords humanMove)//0,0 means special ability
    {
        for(int i=organisms.size()-1;i>=0;i--)
        {
            for(int j=0;j<organisms.get(i).size();j++)
            {
                Organism actual = organisms.get(i).get(j);
                if(actual.isKilled())continue;
                if("Human".equals(actual.getName()))
                {
                    human.action(humanMove);
                    human.setAge(human.getAge()+1);
                    continue;
                }
                actual.action();
                actual.setAge(actual.getAge()+1);
            }
        }
        killOrganisms();
        drawWorld();
    }
    
    private void killOrganisms()
    {
        for(int i=0;i<organisms.size();i++)
        {
            for(int j=0;j<organisms.get(i).size();j++)
            {
                Organism actual = organisms.get(i).get(j);
                if(actual.isKilled())
                {
                    organisms.get(i).remove(j);
                }
            }
        }
    }
    
    public void drawWorld()
    {
        mainFrame.clearSimArea();
        organisms.stream().forEach((organism) -> {
            organism.stream().forEach((actual) -> {
                mainFrame.setFieldText(actual.getName(), actual.getLocation().x, actual.getLocation().y);
            });
        });
    }
    
    
    public WorldManager(int x, int y)
    {
        super(x,y);
        mainFrame = new Frame(x, y, this);
        generateWorld();
    }
    
}
