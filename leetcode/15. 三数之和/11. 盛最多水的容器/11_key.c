#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((b) > (a) ? (b) : (a))

int maxArea(int* height, int heightSize) {
    int ans = 0, left = 0, right = heightSize - 1;
    while (left < right) {
        int area = (right - left) * MIN(height[left], height[right]);
        ans = MAX(ans, area);
        height[left] < height[right] ? left++ : right--;
    }
    return ans;
}