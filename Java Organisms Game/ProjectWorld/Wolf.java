package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Wolf extends Animal{
    public Wolf(Coords coords, World world) {
        super(coords, world);
        this.name="Wolf";
        this.initiative=5;
        this.strength=9;
    }
}
