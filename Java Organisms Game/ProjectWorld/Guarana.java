package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Guarana extends Plant{
    public Guarana(Coords coords, World world) {
        super(coords, world);
        this.name="Guarana";
    }
    @Override
    public boolean specialCollision(Organism other)
    {
        other.setStrength(other.getStrength()+3);
        return true;
    }
}
