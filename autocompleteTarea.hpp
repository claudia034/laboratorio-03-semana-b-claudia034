#ifndef AUTO_COMPLETE_BST_HPP 
 #define AUTO_COMPLETE_BST_HPP 
  
 #include <iostream> 
 #include <algorithm>  
  
 using namespace std; 
  //Estructura principal 
 struct Node{ 
     string data; 
     Node* left; 
     Node* right; 
 }; 
  
 //Primero debemos lograr que se guarde la/las palabra
 void addApalabra(Node*& root, string palabra){ 
    //se puede dar el caso de que root esté vacío, por lo tanto es 
    //importante crear uno para la palabra que el usuario ha ingresado
     if(root == NULL){ 
         root = new Node; 
         root->left = NULL; 
         root ->right = NULL; 
         root ->data = palabra; 
         cout<<"palabra agregada exitosamente"<<endl; 
     } 
     else if(palabra < root->data){ 
         addApalabra(root->right, palabra); 
         cout<<"palabra agregada exitosamente"<<endl; 
     } 
     else if(palabra > root->data){ 
         addApalabra(root->left, palabra); 
         cout<<"palabra agregada exitosamente"<<endl; 
     } 
     else{ //En caso que la palabra ya exista
         cout<<"La palabra ingresada ya existe"<<endl; 
     } 
 } 
  
 //Buscar ocurrencias de palabras
 void OcurrenciasPalabras(Node* root, const string& prefijo){ 
     if(root == NULL){ 
         return; 
     } 
     //Palabras en minuscula
     string lowerprefijo = prefijo; 
     transform(lowerprefijo.begin(), lowerprefijo.end(), lowerprefijo.begin(), ::tolower); 
     string lowerData = root->data; 
     transform(lowerData.begin(), lowerData.end(), lowerData.begin(), ::tolower); 
  
     //Mostrando la palabra
     if(lowerData.find(lowerprefijo) == 0){ 
         cout << "La palabra es: " << root->data << endl; 
     } 
     // buscando con árboles las coincidencias de palabras
     OcurrenciasPalabras(root->right, prefijo); //Derecho
     OcurrenciasPalabras(root->left, prefijo);  //Izquierdo
     
 } 
  
 //Historial de palabras
 void Historial(Node* root){ 
     if(root == NULL){ 
         return; 
     } 
     //recorrer lado izquierdo, luego mostrar palabra y despues recorrer lado derecho 
     Historial(root->left); 
  
     cout<<"La palabra es: " << root->data<<endl; 
  
     Historial(root->right); 
 } 
  
  
 #endif