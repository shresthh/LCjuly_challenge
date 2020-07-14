class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12)
            hour = 0;
        double hour_angle = hour * 30.0 + minutes *.5;
        double minute_angle = minutes * 6.0;
        double diff = abs(hour_angle - minute_angle);
        if(diff > 180)
            diff = (360 - diff);
        return diff;
    }
};
