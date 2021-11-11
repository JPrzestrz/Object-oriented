package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Sowthistle extends Plant{
    public Sowthistle(Coords coords, World world) {
        super(coords, world);
        this.name="Sow Thistle";
    }
    
    @Override
    public void action()
    {
        multiply();
        multiply();
        multiply();
    }
}
