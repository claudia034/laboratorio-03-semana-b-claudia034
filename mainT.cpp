#include "autocompleteTarea.hpp" 
 #include <iostream> 
 #include <string> 
  
 int main() { 
     Node* root = NULL; 
     bool menu = true; 
     int opcion = 0; 
     string palabra; 
  
     do 
     { 
        //Menú que se va a mostrar
         cout<<endl<<"Bienvenido al menu del laboratorio 03"<<endl; 
         cout<<"Por favor, elige una opcion"<<endl<<endl; 
         cout<<"1- Agregar una palabra"<<endl; 
         cout<<"2- Buscar ocurrencias de palabras"<<endl; 
         cout<<"3- Ver historial de palabras guardadas"<<endl; 
         cout<<"4- Salir"<<endl; 
         cout<<"Opcion que desea elegir: "; 
         cin>>opcion; 
  
         //Los diferentes casos que el usuario tiene como opción en el programa
         switch (opcion) 
         { 
         case 1:  //Caso 1-Agregar una palabra
             cout<<"Agregue una palabra: "<<endl; 
             cin.ignore(); 
             //¡Importante! hay que validar que la/las palabras ingresadas no contengan espacios
             getline(cin, palabra); 
             if(palabra.find(' ') != string::npos){ 
                 cout<<"Es importante que la palabra que ingresaste NO contenga espacios"<<endl; //En caso de que contenga espacios, hay que mostrar un mensaje de advertencia
                 cin.ignore(); 
             }else{ 
  
                 addApalabra(root, palabra); 
             } 
             break; 
  
         case 2:  //Caso 2-Ingresar un prefijo para buscar las ocurrencias de palabras
             cout<<"Ingrese un prefijo: "; 
             cin.ignore(); 
             getline(cin, palabra); 
             cout<<"Las palabras que inician con " <<palabra <<" :"<<endl; 
             OcurrenciasPalabras(root, palabra); 
             break; 
  
         case 3: //Caso 3: Búsqueda de palabras
             cout<<"Palabras ordenadas: "<<endl; 
             Historial(root); 
             break; 

         case 4: //Salir
             menu = false; break; 
  
         default: 
             cout<<"La opcion que ingresaste es invalida"<<endl; break; //En caso que el usuario no ingrese una opción del 1-4 deberá aparecer un mensaje 
         } 
  
     } while (menu); 
     return 0; 
 }