package ProjectWorld;

/**
 *
 * @author kprze
 */
public class Human extends Animal{
    
    private int specialAbilityCounter;
    
    private boolean specialAbility;

    public Human(Coords coords, World world) {
        super(coords, world);
        this.specialAbility = false;
        this.specialAbilityCounter = 0;
        this.name="Human";
        this.initiative=4;
        this.strength=5;
    }
    
    public void action(Coords delta)
    {
        if(delta.isEqual(new Coords(0,0)))
        {
            if(specialAbilityCounter==0)
            {
                specialAbility=true;
                specialAbilityCounter++;
            }
        }
        if(specialAbilityCounter>0)
        {
            if(specialAbilityCounter==10)specialAbilityCounter=0;
            if(specialAbilityCounter==5)
            {
                 specialAbility=false;
            }
            specialAbilityCounter++;
        }
        move(new Coords(location.x+delta.x,location.y+delta.y));
    }
    
    @Override
    public boolean specialCollision(Organism other)
    {
        if(specialAbility)
        {
            other.location=world.freeRandomAround(location, 1);
            other.movePermission=false;
            return false;
        }
        return true;
    }
    
    
}