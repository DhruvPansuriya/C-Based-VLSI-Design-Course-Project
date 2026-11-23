; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x24 (bvmul arg0_23 arg2_8)))
(let ((?x720035 (bvmul (_ bv4294967295 32) ?x24)))
(let ((?x2651 (bvmul arg0_23 arg2_7)))
(let ((?x15798 (bvadd ?x2651 ?x720035)))
(and (distinct ?x15798 (_ bv0 32)) true))))))
(check-sat)
