; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_16 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x73290 (bvmul arg0_8 arg1_16)))
(let ((?x60853 (bvmul (_ bv4294967295 32) ?x73290)))
(let ((?x63908 (bvmul arg0_8 arg1_2)))
(let ((?x63156 (bvadd ?x63908 ?x60853)))
(and (distinct ?x63156 (_ bv0 32)) true))))))
(check-sat)
