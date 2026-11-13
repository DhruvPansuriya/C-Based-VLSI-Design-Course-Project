; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x498948 (bvmul arg0_10 arg0_8)))
(let ((?x563755 (bvmul (_ bv4294967295 32) ?x498948)))
(let ((?x364632 (bvmul arg0_10 arg0_2)))
(let ((?x459452 (bvadd ?x364632 ?x563755)))
(and (distinct ?x459452 (_ bv0 32)) true))))))
(check-sat)
