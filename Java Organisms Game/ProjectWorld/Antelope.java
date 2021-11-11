package ProjectWorld;
import java.util.Random;
/**
 *
 * @author kprze
 */
public class Antelope extends Animal{
    public Antelope(Coords coords, World world) {
        super(coords, world);
        this.name="Antelope";
        this.initiative=4;
        this.strength=4;
    }
    @Override
    public void action()
    {
        move(world.randomAround(location,2));
    }
     @Override
    public boolean specialCollision(Organism other)
    {
        Random random = new Random();
        if(random.nextBoolean())
        {
            Coords newLocation = world.freeRandomAround(location, 1);
            if(newLocation==this.location)return true;
            this.move(newLocation);
            return false;
        }
        return true;
    }
}
