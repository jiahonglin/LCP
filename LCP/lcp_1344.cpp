class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double hourAngle = (hour+minutes/60.0)*360/12;
        double minuteAngle = 360/60*minutes;
        
        return min(abs(minuteAngle-hourAngle),360-abs(minuteAngle-hourAngle));
        

    }
};
