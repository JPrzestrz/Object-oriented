package ProjectWorld;
import java.io.Serializable;
/**
 *
 * @author kprze
 */
public class Organism implements Serializable{
    
    boolean killed=false;
    public void kill()
    {
        killed=true;
    }
        
    public boolean isKilled()
    {
        return killed;
    }
    
    protected String name;
    protected int strength;
    
    public int getStrength()
    {
        return this.strength;
    }
    
    public void setStrength(int value)
    {
        this.strength=value;
    }
    
    protected boolean movePermission=true;
    protected int initiative;
    protected int age;
    protected Coords location;
    protected World world;
    
    public Organism(Coords coords, World world)
    {
        this.age=0;
        this.location=coords;
        this.world=world;
    }
    
    public void action()
    {
        
    };
    
    public boolean specialCollision(Organism other)
    {
        return true;
    }
    
    public int getAge()
    {
        return this.age;
    }
    
    public void collision(Organism attacker, Organism deffender)
    {
        if(attacker.getName()==deffender.getName())
        {
            this.multiply();
            attacker.movePermission=false;
            return;
        }
        
        if(!this.specialCollision(deffender))return;
        if(!deffender.specialCollision(this))return;
        
        if(attacker.getStrength()>=deffender.getStrength())
        {
            deffender.kill();
            return;
        }
        attacker.kill();
        return;
    }
    
    public String getName()
    {
        return this.name;
    }
    
    public int getInitiative()
    {
        return this.initiative;
    }
    
    public void setAge(int age)
    {
        this.age=age;
    }
    
    public Coords getLocation()
    {
        return this.location;
    }

    protected void multiply() {
    }
    
}
