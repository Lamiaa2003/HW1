#include <stdio.h>
#include <stdlib.h>

#include <dlfcn.h>

int main()

{

void *surface = dlopen("./surface.so", RTLD_LAZY);

if (!surface)

{

 fprintf(stderr, " Error, can not load surface%s\n", dlerror());

exit(1);

}

void *volume = dlopen("./volume.so", RTLD_LAZY);

if (!volume)

{

 fprintf(stderr, "%s\n", dlerror());

dlclose(surface);

exit(1);

}

void *Diagonal = dlopen("./Diagonal.so", RTLD_LAZY);

if (!Diagonal)

{

 fprintf(stderr, "%s\n", dlerror());

dlclose(surface);

dlclose(volume);

exit(1);

}

 

typedef double CalculateF (double);

CalculateF* calSurface = (CalculateF*)dlsym(surface, "calSurface");

CalculateF* calVolume = (CalculateF*)dlsym(volume,"calVolume");

CalculateF* calDiagonal = (CalculateF*)dlsym(Diagonal,"calDiagonal");

if(!calSurface || !calVolume || !calDiagonal)

 { fprintf(stderr, "%s \n", dlerror());

dlclose(surface);

dlclose(volume);

dlclose(Diagonal);

 

 exit(1); }

double L;

printf("Enter the length of the cube : ");

scanf("\n%lf",&L);

 

printf("Surface Area : %f\n",calSurface(L));

printf("Surface Area : %f\n",calVolume(L));

printf("Diagonal : %f\n",calDiagonal (L));

dlclose(surface);

dlclose(volume);

dlclose(Diagonal);

return 0;
}
