; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_46 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_53 () (_ BitVec 32))
(assert
 (let ((?x72946 (bvmul arg0_22 arg1_46)))
(let ((?x59211 (bvmul (_ bv4294967295 32) ?x72946)))
(let ((?x15641 (bvmul arg0_22 arg1_53)))
(let ((?x60356 (bvadd ?x15641 ?x59211)))
(and (distinct ?x60356 (_ bv0 32)) true))))))
(check-sat)
