package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Hogwed extends Plant{
    public Hogwed(Coords coords, World world) {
        super(coords, world);
        this.name="Hogweed";
        this.strength=10;
    }
    @Override
    public void action()
    {
        Organism other;
        // up 
        Coords loc_temp;
        if(this.location.y!=0)
        {
            loc_temp=new Coords(this.location.x,this.location.y-1);
            other = world.findObject(loc_temp);
            if(other!=null)
            {
                other.kill();
            }
        }
        // down
        if(this.location.y!=world.size.y-1)
        {
            loc_temp=new Coords(this.location.x,this.location.y+1);
            other = world.findObject(loc_temp);
            if(other!=null)
            {
                other.kill();
            }
        }
        //left
        if(this.location.x!=0)
        {
            loc_temp=new Coords(this.location.x-1,this.location.y);
            other = world.findObject(loc_temp);
            if(other!=null)
            {
                other.kill();
            }
        }
        //right
        if(this.location.x!=world.size.x-1)
        {
            loc_temp=new Coords(this.location.x+1,this.location.y);
            other = world.findObject(loc_temp);
            if(other!=null)
            {
                other.kill();
            }
        }
    }
    @Override
    public boolean specialCollision(Organism other)
    {
        other.kill();
        this.kill();
        return false;
    }
}
