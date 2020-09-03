
#include<stdio.h>
#include <stdbool.h>

unsigned mod_pow(int num, int pow, int mod)
{
    int test;
    int n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }

    return test; /* note this is potentially lossy */
}

void left_rotate_by_one(int arr[], int n)
{

/* Shift operation to the left */
int temp = arr[0], i;
for (i = 0; i < n - 1; i++)
arr[i] = arr[i + 1];
arr[i] = temp;
}

void array_left_rotate(int arr[], int no_of_rotations, int n)
{
for (int i = 0; i < no_of_rotations; i++)
left_rotate_by_one(arr, n);   // Function is called for no_of_rotations times
}


void slce(int data, int pr){
    bool boolean;
    long z, s;
    int slce[data], slce_temp[data], wslce[data];
    int count1;
    for(int i=0; i<data; i++){
        boolean = 1;
        z = (mod_pow(pr, i, data)+1)%data;
        //cout<<"z = "<<z<<endl;
        for(int j=0; j<(data-1)/2; j++){
            s = mod_pow(pr, 2*j+1, data);
            //cout<<"s = "<<s<<endl;
            if(s==z && boolean == 1){
                slce[i] = 1;
                boolean = 0;
                count1++;
            }
            if(boolean == 1)
                slce[i] = 0;
               // cout<<slce[i];
        }

    }
    printf("SLCE Output is\n");
    for(int i=0; i<data; i++){
        printf("%d", slce[i]);
    }
    for(int i=0; i<data; i++){
        slce_temp[i] = slce[i];
        }

    array_left_rotate(slce_temp, 2, data);

    for(int i=0; i<data; i++){
        wslce[i] = slce[i]^slce_temp[i];
        }

    printf("\nWSLCE Output is\n");
    for(int i=0; i<data; i++){
        printf("%d", wslce[i]);
    }


}

int main()
{
    slce(223, 5);
    return 0;
}
