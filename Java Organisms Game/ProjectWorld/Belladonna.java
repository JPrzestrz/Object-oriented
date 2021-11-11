package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Belladonna extends Plant{
    public Belladonna(Coords coords, World world) {
        super(coords, world);
        this.name="Belladonna";
        this.strength=99;
    }
    @Override
    public boolean specialCollision(Organism other)
    {
        other.kill();
        this.kill();
        return false;
    }
}
