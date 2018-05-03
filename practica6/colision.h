#ifndef COLISION_H
#define COLISION_H

class Colision{
    
private:
    int intento;
    
public:
    Colision(void){
        intento = 0;
    }
    
    ~Colision(void){}
    
    int get_colision(){
        return intento;
    }
    
    void aumentar(void){
        intento ++;
    }
    
    void disminuir(void){
        intento --;
    }
    
};

#endif /* COLISION_H */

