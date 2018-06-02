#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "Bodega.h"
#include "Platos.h"
#include "Ingrediente.h"

using namespace std;
using std::cout;

int main(){
    int tipo;
    vector <Cliente*> registro;
    vector<Platos*> menu;
    bool end = false;
    Bodega* bodega = new Bodega();
    while(end == false){
    int opcion;
    cout << "" << endl;
    cout << "Menu Administrador" << endl;
    cout << "1) Bodega" << endl;
    cout << "2) Salir" << endl;
    cin >> opcion;
    
    switch(opcion){
        case 1:{
            int opcion2;
            cout << "Menu Bodega" << endl;
            cout << "1) Agregar Ingredientes" << endl;
            cout << "2) Ver Menu" << endl;
            cout << "3) Ver Historial de Ventas" << endl;
            cout << "4) Agregar Platos" << endl;
            cin >> opcion2;
                switch(opcion2){
                    case 1:{
                        string nombre,tipo = "";
                        int aporte;
                        int duracion;
                        int opciontipo;
                        int cantidad;
                        cout << "Ingrese Nombre de Ingrediente"<< endl;
                        cin >> nombre;
                        cout << "Ingrese opcion: 1)Lacteo 2)Vegetal 3)Fruta 4)Otro "<< endl;
                        cin >> opciontipo;
                        if(opciontipo == 1){
                            tipo = "Lacteo";
                        }else if(opciontipo == 2){
                            tipo = "Vegetal";
                        }else if(opciontipo == 3){
                            tipo = "Fruta";
                        }else if(opciontipo == 4){
                            tipo = "Otro";
                        }
                        while(tipo == ""){
                            cout << "Ingrese opcion: 1)Lacteo 2)Vegetal 3)Fruta 4)Otro "<< endl;
                            cin >> opciontipo;
                            if(opciontipo == 1){
                                tipo = "Lacteo";
                            }else if(opciontipo == 2){
                                tipo = "Vegetal";
                            }else if(opciontipo == 3){
                                tipo = "Fruta";
                            }else if(opciontipo == 4){
                                tipo = "Otro";
                            }
                        }
                        cout << "Ingrese Cantidad de Sabor: "<< endl;
                        cin >> aporte;
                        cout << "Ingrese Duracion: "<< endl;
                        cin >> duracion;
                        cout << "Ingrese cantidad de Ingrediente: " << endl;
                        cin >> cantidad;
                        Ingrediente* ing = new Ingrediente(nombre,tipo,aporte,duracion,cantidad);
                        vector <Ingrediente*> ingres;
                        ingres = bodega->getIngredientes();

                        ingres.push_back(ing);

                        bodega->setIngredientes(ingres);

                        cout << bodega->getIngredientes().size() << endl;
                        cout << "Ingrediente Agregado";
                        break;
                    }
                    case 2:{
                            cout << "" << endl;
                            cout << "Platos del Menu" << endl;

                            for(int i =0;i<(bodega->getMenu().size());i++){
                                cout << i+1 << ")" << bodega->getMenu().at(i)->getresena() << endl;
                            }
                            break;
                    }
                    case 3:{

                            break;
                    }
                    case 4:{
                            string resena;
                            int precio;
                            cout << "Ingrese resena" << endl;
                            cin >> resena;
                            cout << "Ingrese precio" << endl;
                            cin >> precio;

                            Platos* plato = new Platos(resena,precio);

                            cout << "" <<endl;
                            cout << "Ingredientes" << endl;
                            for(int i=0;i<(bodega->getIngredientes().size());i++){
                                cout << i+1 << " " << bodega->getIngredientes().at(i)->getNombre() << " Cantidad: " << bodega->getIngredientes().at(i)->getCantidad()<< endl;
                            }
                            bool s = true;
                            int op,g;
                            while(s == true){
                                    cout << "Seleccione Ingrediente a Agregar" << endl;
                                    cin >> op;
                                    Ingrediente* inge = bodega->getIngredientes().at(op-1);

                                    plato->getIngredientes().push_back(inge);
                                    plato->setcantidadSabor(plato->getcantidadSabor() + inge->getAporte() );
                                    
                                    cout << "Agregar Mas? 1)Si 2) No" << endl;
                                    cin >> g;
                                    if(g==1){
                                        s = true;
                                    }else{
                                        s = false;
                                    }
                            }

                            vector <Platos*> pl;
                            pl = bodega->getMenu(); 
                            pl.push_back(plato);
                            bodega->setMenu(pl);
                            cout << (bodega->getMenu().size()) << endl;
                            cout<< "Plato Creado" << endl;

                            break;
                    }
                    default:{
                        break;
                    }
                    break;
                }
                break;
            }
            case 2:{
                int opcion;
                cout << "Salio" << endl;
                end=true;
                break;
            }
            default:{
                break;
            }


        }   
    }
                

}

