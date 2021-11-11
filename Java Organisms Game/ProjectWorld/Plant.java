package ProjectWorld;
import java.util.Random;
/**
 *
 * @author kprze
 */
public class Plant extends Organism{
    
    public Plant(Coords coords, World world)
    {
        super(coords,world);
        this.strength=0;
        this.initiative=0;
    }
    
    @Override
    public void multiply()
    {
        Random random = new Random();
        Coords newCoords = world.freeRandomAround(location, 1);
        if(newCoords.isEqual(location))return;
        if(random.nextInt(10)==0)
        {
            world.addOrganism(newCoords, name);
        }
    }
    
    public void action()
    {
        multiply();
    }
}
