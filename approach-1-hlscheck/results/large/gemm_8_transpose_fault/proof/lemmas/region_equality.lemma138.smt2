; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_29 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_43 () (_ BitVec 32))
(assert
 (let ((?x72928 (bvmul arg0_21 arg1_29)))
(let ((?x66699 (bvmul (_ bv4294967295 32) ?x72928)))
(let ((?x63532 (bvmul arg0_21 arg1_43)))
(let ((?x56031 (bvadd ?x63532 ?x66699)))
(and (distinct ?x56031 (_ bv0 32)) true))))))
(check-sat)
