package ProjectWorld;
import java.util.Random;
/**
 *
 * @author kprze
 */
public class Turtle extends Animal{
    public Turtle(Coords coords, World world) {
        super(coords, world);
        this.name="Turtle";
        this.initiative=1;
        this.strength=2;
    }
    @Override public void action()
    {
        Random random = new Random();
        // 75% 3/4
        if(random.nextInt(4)==0)return;
        move(world.randomAround(location, 1));
    }
    @Override
    public boolean specialCollision(Organism other)
    {
        if(other.getStrength()<5)
        {
            other.movePermission=false;
            this.movePermission=false;
            return false;
        }
        return true;    
    }
}
