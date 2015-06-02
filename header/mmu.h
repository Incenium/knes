class mmu {
    public:
        char rb(int addr);
        char wb(int addr);
    private:
        std::vector<char> m(65536);
};
