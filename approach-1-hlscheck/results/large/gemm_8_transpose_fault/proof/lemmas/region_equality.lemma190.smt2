; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_24 () (_ BitVec 32))
(declare-fun arg0_24 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x63432 (bvmul arg0_24 arg1_24)))
(let ((?x65523 (bvmul (_ bv4294967295 32) ?x63432)))
(let ((?x662 (bvmul arg0_24 arg1_3)))
(let ((?x69239 (bvadd ?x662 ?x65523)))
(and (distinct ?x69239 (_ bv0 32)) true))))))
(check-sat)
