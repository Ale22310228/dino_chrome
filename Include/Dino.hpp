class Dino : public Dibujo, public Actualizable {
public:
    Dino(int x, int y, std::string recurso) : Dibujo(x, y, recurso) {}

    void DesplazarIzq() {
        x -= 1;
    }

    void DesplazarDer() {
        x += 1;
    }

    void Actualizar() override {
        // Actualiza las coordenadas o cualquier otro atributo
    }

    ~Dino() {} // Destructor vacío si no hay recursos adicionales que liberar
};
