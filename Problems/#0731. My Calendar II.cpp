// #0731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Line Sweep
// Time complexity: O(N)
// Space complexity: O(N)
class MyCalendarTwo {
public:
    // Store the number of bookings at each point.
    map<int, int> bookingCount;
    // The maximum number of overlapped bookings allowed.
    int maxOverlappedBooking;

    MyCalendarTwo() { maxOverlappedBooking = 2; }

    bool book(int start, int end) {
        // Increase and decrease the booking count at the start and end
        // respectively.
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;
        // Find the prefix sum.
        for (pair<int, int> bookings : bookingCount) {
            overlappedBooking += bookings.second;

            // If the number of bookings is more than 2, return false.
            // Also roll back the counts for this booking as we won't add it.
            if (overlappedBooking > maxOverlappedBooking) {
                bookingCount[start]--;
                bookingCount[end]++;

                // Remove the entries from the map to avoid unnecessary
                // iteration.
                if (bookingCount[start] == 0) {
                    bookingCount.erase(start);
                }
                if (bookingCount[end] == 0) {
                    bookingCount.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};

// Approach 1: Using Overlapped Intervals
// Time complexity: O(N)
// Space complexity: O(N)
class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Returns false if the new booking overlaps with the existing
        // double-booked bookings.
        for (pair<int, int> booking : overlapBookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                return false;
            }
        }

        // Add the double overlapping if any with the new booking.
        for (pair<int, int> booking : bookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                overlapBookings.push_back(
                    getOverlapped(booking.first, booking.second, start, end));
            }
        }

        // Add the booking to the list of bookings.
        bookings.push_back({start, end});
        return true;
    }

private:
    // Return true if the booking [start1, end1) & [start2, end2) overlaps.
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    // Return overlapping booking between [start1, end1) & [start2, end2).
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */