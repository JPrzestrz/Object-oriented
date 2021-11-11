package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Fox extends Animal{
    public Fox(Coords coords, World world) {
        super(coords, world);
        this.name="Fox";
        this.initiative=7;
        this.strength=3;
    }
    @Override
    public void action()
    {
        Coords newCoords;
        int i=10;
        do{
            if(i==0)return;
            newCoords = world.randomAround(location, 1);
            i--;
        } while(!world.isEmpty(newCoords) && world.findObject(newCoords).getStrength()>this.strength);
        move(newCoords);
    }
}
