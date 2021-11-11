package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Animal extends Organism{

    public Animal(Coords coords, World world) {
        super(coords, world);
    }
    
    @Override
    protected void multiply()
    {
        Coords newLoc = world.freeRandomAround(location, 1);
        if(newLoc.isEqual(this.location))return;
        world.addOrganism(newLoc, this.getName());
    }
            
    
    @Override
    public void action()
    {
        this.movePermission=true;
        move(world.randomAround(location,1));
    }
    
    protected void move (Coords newCoords)
    {
        if(newCoords.isEqual(location))return;
        if(!world.inBoundaries(newCoords))return;
        if(world.isEmpty(newCoords))
        {
            location=newCoords;
            return;
        }
        Organism enemy = world.findObject(newCoords);
        
        if(!enemy.isKilled())collision(this, enemy);
        
        if(!this.killed && this.movePermission)location=newCoords;
    }
    
}
