; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x464744 (bvmul arg0_6 arg1_10)))
(let ((?x404229 (bvmul (_ bv4294967295 32) ?x464744)))
(let ((?x7983 (bvmul arg0_6 arg1_11)))
(let ((?x479416 (bvadd ?x7983 ?x404229)))
(and (distinct ?x479416 (_ bv0 32)) true))))))
(check-sat)
