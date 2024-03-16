class Keyboard {
public:
    // Запрещаем копирование и присваивание
    Keyboard(const Keyboard&) = delete;
    Keyboard& operator=(const Keyboard&) = delete;

    static Keyboard& getInstance() {
        static Keyboard instance; 
        return instance;
    }

    void change_key(char _key) { key = _key; }

    // getters
    char get_key() { return key; }

private:
    char key;

    Keyboard() {}
    ~Keyboard() {}
};
