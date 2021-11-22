# 3 - Le saviez-vous ?

Ce chapitre est juste une excuse pour vous dire des trucs utiles et pratiques :D  

## sprintf

Le saviez-vous ? Vous pouvez, en plus de mettre du texte "formaté" à l'écran, le mettre dans un texte !  
  
`sprintf(char* string, char* texte, ...);`  
  
Exemple:  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  char str[32];
  sprintf(str, "%d", argc-1);
  puts("Vous avez spécifié: ");
  puts(str);
  puts("arguments (En plus du programme).");
  
  return 0;
}
```  

Voilà une méthode simple pour convertir un nombre en chaîne de caractères, on verra par la suite qu'il y a mieux :)  

## sscanf

Le saviez-vous ? Vous pouvez faire un scanf qui utilise un texte comme entrée à la place du clavier !  
  
`sscanf(char* entree, char* texte, ...);`  
  
Exemple:  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  char* nombre_str = "0";
  int nombre = 0;
  sscanf(nombre_str, "%d", &nombre);
  return nombre;
}
```  

Voilà une méthode simple pour convertir une chaîne de caractère en nombre, et bien évidemment, on verra plus tard qu'il y a mieux :D  

## strlen

Vous le savez déjà, on peut savoir la taille d'un type avec sizeof(type), d'un tableau avec sizeof(tableau),  
le nombre d'élément d'un tableau avec sizeof(tableau) / sizeof(type), ou juste sizeof(tableau) pour une chaîne de caractères (Vu que sizeof(char) = 1).  
Or, sizeof s'effectue en compile-time, c'est à dire pendant la compilation, donc ne peut pas mesurer une entrée utilisateur (Par exemple).  
De plus, si on utilise sizeof() sur une chaîne de caractères, il va aussi compter le null terminator ('\0'), donc il faudra retirer 1.  
Mais heureusement, il existe un moyen très simple de règler les deux problèmes !  
  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    puts("Utilisation: longueur <texte>");
    return 1;
  }
  
  char* texte = argv[1];
  unsigned int longueur = 0;
  while(*texte) //N'oubliez pas que null terminator c'est '\0', que en ASCII '\0' = 0, et que 0 est faux en C.
  //Au pire remplacez le par while(*texte != '\0'), mais c'est moins performant
  {
    longueur++; //On ajoute 1 à longueur
    texte++; //On se déplace vers le prochain élément du tableau "texte"
  }
  
  printf("%s mesure %d caractères !\n", argv[1], longueur);
  return 0;
}
```  

Mais rassurez vous, quelqu'un à déjà écrit ça en fonction pour notre bien ! :D  
  
Ajoutez la bibliothèque string.h, qui contient plein d'outils pour ravir vos char* ! :D  
`#include <string.h>`  
Désormais, pour avoir la longueur d'une chaîne de caractère, faîtes juste:  
`strlen(char* texte);`  
