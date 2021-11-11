package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Sheep extends Animal{
    public Sheep(Coords coords, World world) {
        super(coords, world);
        this.name="Sheep";
        this.initiative=4;
        this.strength=4;
    }
}
