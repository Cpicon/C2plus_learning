#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Las funciones se declaran antes del main

// Void es si la funcion solo imprime datos
void imprimirCosas(){

    printf("Game over....");

}

void fuck_pointers(){
    // Declaro dos variables numericas
    int A = 123, B = 456;
    // declaro una variable tipo apuntador
    //(Es importante saber que está varible tambien tiene su propia direccion en memoria)
    int* pointer_dir;
    // obtengo la dirección de memoria de la variable 'A'
    pointer_dir = &A;

    //Imprimo el valor del pointer( Que será la direccion de memoria de 'A')
    cout << pointer_dir << endl; //Imprime 0x61fe1c
    // Imprimo la direccion en memoria del apuntador (Que será distinta a su valor)
    cout << &pointer_dir << endl; // Imprime 0x61fe10
    //Imprimo el valor que esta almacenado en la direccion de memoria que el apuntador guarda
    cout << *pointer_dir << endl;// Imprime el valor de A = 123

    cout << "------" << endl;
    //Ahora cambio el valor almacenado en la dirección de memoria que el apuntador estaba guardando
    // Es decir, ahora el valor de A tambien cambiará
    *pointer_dir = B;
    //Imprimo la dirección que guarda el apuntador ( Es decir, está no ha cambiado)
    cout << pointer_dir << endl;//Imprime 0x61fe1c
    // Imprimo la direccíon del apuntador ( Realmente, esta no cambia y ni deberia)
    cout << &pointer_dir << endl;// Imprime 0x61fe10
    //Imprimo el contiendo de la direccion asignada (A), pero esta ahora se le asignó el valor B
    cout << *pointer_dir << endl;//Imprime el valor de B = 456
    cout << "------" << endl;
    // Eventualmente,al cambiar el contenido en la dirección que almacena el apuntador (pointer_dir),
    //cambia el contenido de la variable a la cual corresponde esta variable (A).
    cout << A << endl;//Imprime el valor de B = 456
    //Re asignamos el valor de A.
    A = 123;
    //cambiamos la direccion de memoria que almacenara el apuntador
    pointer_dir = &B;
    cout << "------" << endl;
    //Al imprimir la nueva dirección, vemos que esta cambió.
    cout << pointer_dir << endl;//Imprime 0x61fe18
    // Ahora vemos, que el apuntador tiene una dirrecion que apunta a otro contenido.
    //En este caso el valor de B.
    cout << *pointer_dir << endl;//Imprime B = 456
    // si modificamos el valor de B, automaticamente cambia el valor que se obtiene
    //al usar el apuntador (*pointer_dir)
    B=789;

    cout << "------" << endl;
    // la dirección que almacena, sigue siendo la misma
    cout << pointer_dir << endl;//Imprime 0x61fe18
    //pero su contenido cambió al modificar la variable original
    cout << *pointer_dir << endl;//Imprime B = 789
}
//Clase padre
class Mage{
public:
    //Constructor
    Mage(int BasePower, int BaseHp, string name)
    {
        Power = BasePower;
        hp = BaseHp;
        Name = name;
    }
    float Damage()
    {
        return Power;
    }
    void GetDamage(int Value)
    {
        hp= hp-Value;
    }
    int life()
    {
        return hp;
    }
    string get_name()
    {
        return Name;
    }
protected:
    int Power, hp;
    string Name;
};

//Clase hija 1
class IceMage : public Mage
{
    public:
    IceMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower + 1;
        hp = BaseHp +1;
        Name = name;
    }
    int ice_attack(){

        return  (rand() % Power) + 1;
    }
};

//Clase hija 2
class FireMage : public Mage
{
    public:
    FireMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower;
        hp = BaseHp + 10;
        Name = name;
    }
    int fire_attack(){
        return  (rand() % Power) + 1;
    }
};
int main()
{
    Mage* Current_mage;
    Mage Harry(10, 100, "Harry");
    IceMage Dumbledore(11, 100, "Dumbledore");
    FireMage Gandalf(11,100, "Gandalf");
    //fuck_pointers();
    //imprimirCosas();
    bool chance = true;
    int attack_value;
    for (int i=0;i<10;i++){
        if (chance){
            Current_mage = &Dumbledore;
            attack_value = Dumbledore.ice_attack();
            cout<<" attack :"<<attack_value;
            Current_mage->GetDamage(attack_value);
            cout<<Current_mage->get_name()<<"- current life :"<<Current_mage->life()<<endl;
            chance = false;
        }
        else{
            Current_mage = &Gandalf;
            attack_value = Gandalf.fire_attack();
            cout<<" attack :"<<attack_value;
            Current_mage->GetDamage(attack_value);
            cout<<Current_mage->get_name()<<"- current life :"<<Current_mage->life()<<endl;
            chance = true;
        };
    }
    return 0;
}
