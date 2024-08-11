//Waqas_22i2469

// Assignment # 2

/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Creature
{
private:
    string name;
    int level;
    int health_points;
    int force;
    int position;
    int attackPoints = 0;

public:
    Creature (string n = "\0", int l = 0, int hp = 0, int f = 0, int p = 0)
    {
        name = n;
        level = l;
        health_points = hp;
        force = f;
        position = p;
        attackPoints = level * force;
    }

    bool alive()
    {
        if (health_points > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int AttackPoints()
    {
        bool isAlive = alive();

        if (isAlive == true)
        {
            attackPoints = level * force;
            return attackPoints;
        }
        else
        {
            attackPoints = 0;
            return attackPoints;
        }
    }

    void Move(int addPositions)
    {
        position += addPositions;
    }

    void GoodBye()
    {
        cout << "(English: " << name << " is no more!)" << endl;
    }

    void Weak(int subtractPoints)
    {
        bool isAlive = alive();

        /*cout << endl <<subtractPoints << "here" << endl;*/

        if (isAlive == true)
        {
            health_points -= subtractPoints;

            if (health_points <= 0)
            {
                health_points = 0;
                attackPoints = 0;

                GoodBye();
            }
        }
        else //------------------------------------------------------------------------------------------------------------------do here------------------------------------------
        {

        }
    }

    void display()
    {
        cout << name << ", level: " << level << ", health_status: " << health_points << ", force: " << force << ", Attacking Points: " << attackPoints << ", position: " << position << endl;
    }

    int distance(int obj_p) 
    {
        int d = position - obj_p;

        if (d < 0)
        {
            d *= -1;
        }

        return d ;
    }

    // --------------------- GETTERS SETTERS START ---------------------

    string getName() const
    {
        return name;
    }

    void setName(string n)
    {
        name = n;
    }

    int getLevel() const
    {
        return level;
    }

    void setLevel(int l)
    {
        level = l;
    }

    int getHealthPoints() const
    {
        return health_points;
    }

    void setHealthPoints(int hp)
    {
        health_points = hp;
    }

    int getForce() const
    {
        return force;
    }

    void setForce(int f)
    {
        force = f;
    }

    int getPosition() const
    {
        return position;
    }

    void setPosition(int p)
    {
        position = p;
    }

    int getAttackPoints() const
    {
        return attackPoints;
    }

    void setAttackPoints(int ap)
    {
        attackPoints = ap;
    }

    // --------------------- GETTERS SETTERS END ---------------------

};

class Dragon : public Creature
{
private:
    int flame_range;

public:
    Dragon(string name = "NIL", int level = 0, int health_points = 0, int force = 0, int fr = 0, int position = 0) : Creature(name , level , health_points , force , position )
    {
        flame_range = fr;
    }

    void Fly(int pos)
    {
        Move(pos);
    }

    void BlowFame(Creature& obj)
    {
        bool dragon_status = alive();
        bool creauture_status = obj.alive();
        int d = distance(obj.getPosition());
        
        if (dragon_status == true && creauture_status == true && d <= flame_range)   
        {
            int attackp = AttackPoints();

            obj.Weak(attackp);
            Weak(d);
        }


        dragon_status = alive();
        creauture_status = obj.alive();
        if (dragon_status == true && creauture_status == false)
        {
            int new_level = getLevel();
            new_level += 1;
            setLevel(new_level);
            int attackP = getLevel() * getForce();
            setAttackPoints(attackP);
        }
    }

};

class Ichneumon : public Creature
{
private:
    int neck_length;
    int poison_dose;

public:
    Ichneumon(string name = "\0", int level = 0, int health_points = 0, int force = 0, int nl = 0, int pd = 0, int position = 0) :Creature(name, level, health_points, force, position)
    {
        neck_length = nl;
        poison_dose = pd;
    }

    void Inject_Poison(Creature& obj)
    {
        bool ichneumon_status = alive();
        bool creauture_status = obj.alive();
        int d = distance(obj.getPosition());
        
        if (ichneumon_status == true && creauture_status == true && d <= neck_length)
        {
            int attackp = AttackPoints();
            obj.Weak(attackp + poison_dose);
            Weak(d); // According to example output
        }

        ichneumon_status = alive();
        creauture_status = obj.alive();
        if (ichneumon_status == true && creauture_status == false)
        {
            int new_level = getLevel();
            new_level += 1;
            setLevel(new_level);
            int attackP = getLevel() * getForce();
            setAttackPoints(attackP);
        }
    }
};

void Fight(Dragon & obj1 , Ichneumon & obj2)
{
    if (obj1.getHealthPoints() != 0 && obj2.getHealthPoints() != 0)
    {
        obj2.Inject_Poison(obj1);
        obj1.BlowFame(obj2);
    }
}

/*-------------------------Main----------------------------------*/

int main()
{
    Dragon dragon("Dragon red", 2, 10, 3, 20);
    Ichneumon  ichneumon("ichneumon evil", 2, 10, 1, 10, 1, 42);

    dragon.display();
    cout << "is preparing for fight with :" << endl;
    ichneumon.display();

    cout << endl;
    cout << "1st Fight :" << endl;
    cout << "    the creature-s are not within range, so can not Attacked."
        << endl;
    Fight(dragon, ichneumon);

    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();

    cout << endl;
    cout << "Dragon has flown close to ichneumon :" << endl;
    dragon.Fly(ichneumon.getPosition() - 1);
    dragon.display();

    cout << endl;
    cout << "ichneumon moves :" << endl;
    ichneumon.Move(1);
    ichneumon.display();

    cout << endl;
    cout << "2nd Fight :" << endl;
    cout << ""
        << "+ ichneumon inflicts a 3-point attack on dragon\n"
        " [ level (2) * force (1) + poison (1) = 3 ] ;\n"
        "+ Dragon inflicts a 6-point attack on ichneumon\n"
        "[ level (2) * force (3) = 6 ] ;\n"
        "+ during his attack, dragon loses two additional points\n"
        "      [ corresponding to the distance between dragon and ichneumon : 43 - 41 = 2 ]." << endl;
    Fight(dragon, ichneumon);

    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();

    cout << endl;
    cout << "Dragon moves by one step " << endl;
    dragon.Move(1);
    dragon.display();

    cout << endl;
    cout << "3rd Fight :" << endl;
    cout << "  + ichneumon inflicts a 3-point attack on dragon \n "
        "    [ level (2) * force (1) + poison (1) = 3 ] ; \n "
        "+ Dragon inflicts a 6-point attack on ichneumon \n "
        "      [ level (2) * force (3) = 6 ] ; \n"
        "+ during his attack, dragon lost 1 additional life point.\n"
        "[ corresponding to the distance between dragon and ichneumon : 43 - 42 = 1 ] ;\n"
        "+ ichneumon is defeated and the dragon rises to level 3" << endl;
    Fight(dragon, ichneumon);

    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();

    cout << endl;
    cout << "4th Fight :" << endl;
    cout << "    when one creatures is defeated, nothing happpens" << endl;
    Fight(dragon, ichneumon);

    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();

    return 0;
}


