//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_APPLICATION_H
#define ANIMATIONPROGRAMMING_APPLICATION_H


class Application {
private:
    Application(const Application&);
    Application& operator=(const Application&);

public:
    inline Application() { }
    inline virtual ~Application() { }

    inline virtual void Initialize() {}
    inline virtual void Update(float delta) {}
    inline virtual void Render(float aspectRatio) {}
    inline virtual void Shutdown() {}
};


#endif //ANIMATIONPROGRAMMING_APPLICATION_H
