package ProjectWorld;
import java.util.ArrayList;
import DisplayPack.Frame;
import java.util.Random;
/**
 *
 * @author kprze
 */
public class World {
    
    Coords size;
    protected ArrayList <ArrayList <Organism>> organisms;
    protected Frame mainFrame;
    
    public World(int x, int y)
    {
        size=new Coords(x,y);
        
        organisms = new ArrayList <>();
        for(int i=0;i<10;i++)
        {
            organisms.add(new ArrayList <>());
        }
    }
    
    // next
    
    public Organism addOrganism(Coords coords, String name)
    {
        if(!isEmpty(coords))return null;
        Organism newOrganism;
        switch (name)
        {
            case "Antelope":
                newOrganism = new Antelope(coords,this);
                break;
            case "Fox":
                newOrganism = new Fox(coords,this);
                break;
            case "Sheep":
                newOrganism = new Sheep(coords, this);
                break;
            case "Turtle":
                newOrganism = new Turtle(coords, this);
                break;
            case "Wolf":
                newOrganism = new Wolf(coords, this);
                break;
            case "Human":
                newOrganism = new Human(coords,this);
                break;
            case "Grass":
                newOrganism = new Grass(coords,this);
                break;
            case "Sow Thistle":
                newOrganism = new Sowthistle(coords,this);
                break;
            case "Guarana":
                newOrganism = new Guarana(coords,this);
                break;
            case "Belladonna":
                newOrganism = new Belladonna(coords,this);
                break;
            case "Sosnowsky's Hogweed":
                newOrganism = new Hogwed(coords,this);
                break;
            default:
                return null;
        }
        organisms.get(newOrganism.getInitiative()).add(newOrganism);
        return newOrganism;
    }
    
    public boolean isEmpty(Coords coords)
    {
        for(ArrayList <Organism> organism : organisms)
        {
            for(Organism actual : organism)
            {
                if(actual.location.isEqual(coords))return false;
            };
        }
        return true;
    }
    
    
    public boolean inBoundaries(Coords coords)
    {
        if(coords.x >= 0 && coords.x <size.x && coords.y >=0 && coords.y<size.y)return true;
        return false;
    }
    
    public Organism findObject(Coords coords)
    {
        for(ArrayList <Organism> organism : organisms)
        {
            for(Organism actual : organism)
            {
                if(actual.location.isEqual(coords))return actual;
            };
        }
        return null;
    }
    
    public Coords randomAround(Coords center, int range)
    {
        Random random = new Random();
        Coords newCoords = new Coords(center.x+(random.nextInt(3)-1)*range,center.y+(random.nextInt(3)-1)*range);
        while(!inBoundaries(newCoords) || newCoords.equals(center))
        {
            newCoords = new Coords(center.x+(random.nextInt(3)-1)*range,center.y+(random.nextInt(3)-1)*range);
        }
        return newCoords;
    }
    
    public Coords freeRandomAround(Coords center, int range)
    {
        int triesCounter=50;
        Random random = new Random();
        Coords newCoords = new Coords(center.x+(random.nextInt(3)-1)*range,center.y+(random.nextInt(3)-1)*range);
        while(!inBoundaries(newCoords) || newCoords.equals(center) || !isEmpty(newCoords))
        {
            if(triesCounter==0)return center;
            newCoords = new Coords(center.x+(random.nextInt(3)-1)*range,center.y+(random.nextInt(3)-1)*range);
            triesCounter--;
        }
        return newCoords;
    }
    
}

