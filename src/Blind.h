
class Blind {
public:
  Blind(int upPin, int downPin);
  void stop();
  void up();
  void down();

private:
  int upPin;
  int downPin;
};
