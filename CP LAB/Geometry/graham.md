# Graham’s Scan Algorithm (Step by Step)

We are given a set of points in 2D, and we want to find the **convex hull** (smallest convex polygon enclosing all points).

 

## Step 1: Find Pivot

* Choose the lowest **y-coordinate** point.
* If tie → choose the **leftmost x**.
* Guarantees a unique starting point (always part of hull).

**Example:**

```
Points = {(0,3), (2,2), (1,1), (2,1), (3,0), (0,0), (3,3)}
Pivot = (0,0)
```


## Step 2: Sort by Polar Angle

* Sort all other points by **angle w\.r.t pivot**.
* If two points have the same angle (collinear), keep the **farther one** (inner point is useless).
* Now points are ordered like “sweeping a line” counter-clockwise around pivot.

**Example:**

```
Pivot = (0,0), points = (1,1), (2,0), (0,2)
Order = (2,0) → (1,1) → (0,2)
```

 

## Step 3: Traverse Points

* Walk through sorted points.
* Maintain a **stack of hull vertices**.
* For each new point:

  * Check **turn direction** of last two points + new point:

    * Left turn (CCW) → good, keep it.
    * Right turn (CW) → pop last point (not on hull).
* Continue until all points are processed.

 

## Step 4: Output

* The stack now contains convex hull points in order.

 

## Why Orientation?

* Orientation function tells direction of a turn formed by three points `p, q, r`.

**Formula:**

```
val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy)
```

* val == 0 → collinear
* val > 0 → clockwise turn
* val < 0 → counter-clockwise turn

👉 **Why needed?**

* To decide if the last point stays on the hull.
* If turn is right (CW), the middle point is inside, not on hull → remove it.

 

## Why Compare (Sorting)?

* We need points in **increasing polar angle** from pivot.

Instead of slow `atan2`, use **orientation test**:

```
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) return distSq(p0, p1) < distSq(p0, p2); // farther last
    return (o == 2); // CCW means p1 before p2
}
```

 

## Intuition with Analogy

* Imagine standing at the pivot with a rotating **laser beam**:

  * As it rotates CCW, you encounter points → that’s the sorting step.
  * If the beam turns right → you went inside the polygon → backtrack (pop).

Orientation = heart of the algorithm (decides left/right turn).
Compare = ensures sweeping in correct CCW order.

 

## Complexity

* **Time**: O(n log n) (sorting dominates)
* **Space**: O(n) (stack + sort)
