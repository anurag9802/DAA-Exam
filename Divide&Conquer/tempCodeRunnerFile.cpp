for(int i=low;i<high;i++){
        if(a[i]<pivot){
            k++;
            swap(a[k],a[i]);
        }            
    }