GetPosition(List[] list, ElemType e){
    int left = 0;
    int right = list.length - 1;
    int midPos = (left + right) / 2;
    while(list[midPos]!=e){
        if(left == right){
            return ERROR;
        }
        if(list[mimPos] > e){
            right = midPos - 1;
            midPos = (left+right) /2;
        }
        else{
            left = midPos+1;
            midPos = (left+right)/2;
        }
    }

}