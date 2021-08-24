#include <iostream>
#include <memory>

//Model
class Bloco {
    private: 
        float a, v, x, m, f_ext;
    public:
        Bloco(float a_novo, float v_novo, float x_novo, float m_novo, float f_ext_novo);
        float get_a();
        float get_v();
        float get_x();
        float get_f_ext();
        void set_v(float v_novo);
        void set_x(float x_novo);
};

float Bloco::get_a() {
    return a;
}

float Bloco::get_v() {
    return v;
}

float Bloco::get_x() {
    return x;
}

float Bloco::get_f_ext() {
    return f_ext;
}

void Bloco:: set_v(float v_novo) {
    v = v_novo;
}

void Bloco:: set_x(float x_novo) {
    x = x_novo;
}

Bloco::Bloco(float a_novo, float v_novo, float x_novo, float m_novo, float f_ext_novo) {
    a = a_novo;
    v = v_novo;
    x = x_novo;
    m = m_novo;
    f_ext = f_ext_novo;
}

class Mola {
    private:
        float k, b;
    public:
        Mola(float k_novo, float b_novo);  
        float get_k();
        float get_b();
};

float Mola::get_k() {
    return k;
}

float Mola::get_b() {
    return b;
}

Mola::Mola(float k_novo, float b_novo) {
    k = k_novo;
    b = b_novo;
}

//Controller
class Sistema {
    private:
        float T;
        Bloco block;
        Mola mola;
    public:
        Sistema(Bloco block_novo, Mola mola_novo, float T_novo);
        void atualiza_velocidade();
        void atualiza_espaco();
        float forca_elastica();
        float forca_amort();
        float forca_resultante();
};

void Sistema::atualiza_velocidade() {
    float temp = block.get_v() + T*block.get_a();
    block.set_v(temp); 
}

void Sistema::atualiza_espaco() {
    float temp = block.get_x() + T*block.get_v();
    block.set_x(temp);
}

float Sistema::forca_resultante() {
    float forca_elastica = mola.get_k() * block.get_x();
    float mola.get_b() * block.get_v();
    return (block.get_f_ext() - forca_amort() - forca_elastica());
}

Sistema::Sistema(Bloco block_novo, Mola mola_novo, float T_novo) {
    T = T_novo;
    block = block_novo;
    mola = mola_novo;
}

int main() {
    float x;
    std::shared_ptr<Bloco> bloco (new Bloco(-2.0, 0, 0, 5.0, 0));
    std::shared_ptr<Mola> mola (new Mola(2, 0.5));
    std::shared_ptr<Sistema> sis (new Sistema(bloco, mola, 0.01));
    
    for (int i=0; i < 100; i++) {
        sis->atualiza_velocidade();
        sis->atualiza_espaco();
        x = sis->forca_resultante();
        std::cout<<x<<std::endl;
    }
    return 0;
}
