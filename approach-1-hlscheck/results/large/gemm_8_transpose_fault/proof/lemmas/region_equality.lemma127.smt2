; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_16 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x72911 (bvmul arg0_16 arg1_16)))
(let ((?x69932 (bvmul (_ bv4294967295 32) ?x72911)))
(let ((?x63553 (bvmul arg0_16 arg1_2)))
(let ((?x55342 (bvadd ?x63553 ?x69932)))
(and (distinct ?x55342 (_ bv0 32)) true))))))
(check-sat)
